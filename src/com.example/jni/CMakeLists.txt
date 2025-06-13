#③生成动态库.dll文件
add_library(jnidll SHARED test.c jni.h jni_md.h com_example_jnitt_HelloNative.h)
