#include <stdio.h>
#include <string.h>
#include "com_example_jnitt_HelloNative.h"

/*
 * Class:     com_example_local_HelloNative
 * Method:    fun1
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jnitt_HelloNative_fun1
        (JNIEnv * env, jobject obj) {
    printf("test jni function");
}

/*
 * Class:     com_example_local_HelloNative
 * Method:    fun2
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jnitt_HelloNative_fun2
        (JNIEnv * env, jobject obj, jstring k1) {

    const char * name = (*env)->GetStringUTFChars(env,k1,NULL);
    char msg[60] = "Hello ";
    jstring result;
    strcat(msg,name);
    (*env)->ReleaseStringUTFChars(env,k1,name);
    result = (*env)->NewStringUTF(env,msg);
    return result;
}

/*
 * Class:     com_example_local_HelloNative
 * Method:    add
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnitt_HelloNative_add
        (JNIEnv * env, jobject obj, jint v1, jint v2) {
    return  v1 + v2;
}