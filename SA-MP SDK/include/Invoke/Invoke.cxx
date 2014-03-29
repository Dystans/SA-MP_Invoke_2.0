/*
    SA-MP 0.3z Invoke v1.0
    Copyright (c) 2014, Linux_Shines
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Linux_Shines nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL LINUX_SHINES BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "Invoke.hxx"

Invoke * Invoke_Call;

int Invoke::Call_Native(const INVOKE::Native * native, ...) {
	if(amx_list.empty() || amx_map.find(native -> name) == amx_map.end()) {
		return false;
	}

	unsigned int amx_addr = amx_map[native -> name], count = strlen(native -> data), variables = 0;
	long int * params = new long int[count + 1], *physAddr[6];
	params[0] = count * sizeof(long int);
	char * input;
	va_start(input, native);
	for(unsigned int i = 0; i < count; ++i) {
		switch(native -> data[i]) {
			case 'd': {
				params[i + 1] = va_arg(input, int);
			} break;
			case 'f': {
				float value = (float) va_arg(input, double);
				params[i + 1] = amx_ftoc(value);
			} break;
			case 'i': {
				params[i + 1] = va_arg(input, int);
			} break;
			case 'p': {
				va_arg(input, void *);
				int size = va_arg(input, int);
				amx_Allot(amx_list.front(), size, &params[++i], &physAddr[variables++]);
				params[i + 1] = size;
			} break;
			case 's': {
				char * string = va_arg(input, char *);
				amx_Allot(amx_list.front(), strlen(string) + 1, &params[i + 1], &physAddr[variables++]);
				amx_SetString(physAddr[variables - 1], string, 0, 0, strlen(string) + 1);
			} break;
			case 'v': {
				va_arg(input, void *);
				amx_Allot(amx_list.front(), 1, &params[i + 1], &physAddr[variables++]);
			} break;
		}
	}
	va_end(input);
	amx_Function_t amx_Function = (amx_Function_t) amx_addr;
	int value = amx_Function(amx_list.front(), params);
	if(variables) {
		variables = 0;
		va_start(input, native);
		for(unsigned int i = 0; i < count; ++i) {
			switch(native -> data[i]) {
				case 'p': {
					char * text = va_arg(input, char *);
					int size = va_arg(input, int);
					amx_GetString(text, physAddr[variables++], 0, size);
					amx_Release(amx_list.front(), params[++i]);
				} break;
				case 's': {
					amx_Release(amx_list.front(), params[i + 1]);
				} break;
				case 'v': {
					unsigned int * value = va_arg(input, unsigned int *), * returnValue = (unsigned int *) physAddr[variables++];
					* value = * returnValue;
					amx_Release(amx_list.front(), params[i + 1]);
				} break;
				default: {
					va_arg(input, void *);
				} break;
			}
		}
		va_end(input);
	}
	delete[] params;
	return value;
}
#define callNative Call_Native

int Invoke::getAddresses() {
	if(gotAddresses) {
		return true;
	}
	AMX_HEADER * amx_hdr = (AMX_HEADER *) (amx_list.back()) -> base;
	std::size_t size = sizeof(INVOKE::names) / sizeof(const char *);
	for(std::size_t i = 0; i < size; ++i) {
		amx_FindNative(amx_list.back(), INVOKE::names[i], &amx_idx);
		if(amx_idx != std::numeric_limits <int>::max()) {
			unsigned int amx_addr = (unsigned int) ((AMX_FUNCSTUB *) ((char *) amx_hdr + amx_hdr -> natives + amx_hdr -> defsize * amx_idx)) -> address;
			if(amx_addr) {
				if(amx_map.find(INVOKE::names[i]) == amx_map.end()) {
					amx_map.insert(std::make_pair(INVOKE::names[i], amx_addr));
				}
			}
		}
	}
	if(amx_map.size() == size) {
		gotAddresses = true;
		return true;
	}
	return false;
}
