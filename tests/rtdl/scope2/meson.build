libfoo = shared_library('foo', 'libfoo.c')
libbar = shared_library('bar', 'libbar.c', build_rpath: test_rpath, link_with: libfoo)
libbaz = shared_library('baz', 'libbaz.c')
test_depends = [libfoo, libbar, libbaz]

libfoo_native = shared_library('native-foo', 'libfoo.c', native: true)
libbar_native = shared_library('native-bar', 'libbar.c', build_rpath: test_rpath, link_with: libfoo_native, native: true)
libbaz_native = shared_library('native-baz', 'libbaz.c', native: true)
test_native_depends = [libfoo_native, libbar_native, libbaz_native]
