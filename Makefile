CEXT_NAME=sprite3d
CEXT_EXTENSION=.h
CEXT_PATH=lib/c_renderer/
CEXT_FILES=vector.c matrix.c vertex.c sprite.c body.c scene.c camera.c counting_sort.c radix_sort.c merge_sort.c renderer.c
CEXT_SRC=$(addprefix $(CEXT_PATH),$(CEXT_FILES))
BINDER=../dragonruby-bind
BINDER_FFI_MODULE=Sprite3D_C
BINDER_CFLAGS='-I /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include -I../include -I.'
BINDER_OUTPUT_EXTENSION=-bindings.c
CC=clang
CFLAGS=-shared -isystem include -lc -I../include -I. -fPIC
DYLIB_PATH=native/macos/
DYLIB_EXTENSION=.dylib

csprite3d:
	$(BINDER) --compiler-flags=$(BINDER_CFLAGS) --ffi-module=$(BINDER_FFI_MODULE) --output=$(CEXT_PATH)$(CEXT_NAME)$(BINDER_OUTPUT_EXTENSION) $(CEXT_PATH)$(CEXT_NAME)-bridge$(CEXT_EXTENSION)
	$(CC) $(CFLAGS) -o $(DYLIB_PATH)$(CEXT_NAME)$(DYLIB_EXTENSION) $(CEXT_SRC) $(CEXT_PATH)$(CEXT_NAME)$(BINDER_OUTPUT_EXTENSION)

clean:
	rm -f $(CEXT_PATH)$(CEXT_NAME)$(BINDER_OUTPUT_EXTENSION) $(DYLIB_PATH)$(CEXT_NAME)$(DYLIB_EXTENSION)
