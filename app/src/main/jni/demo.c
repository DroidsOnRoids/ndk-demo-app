#include<jni.h>
#include<stdlib.h>
#include <android/log.h>

#define  LOG_TAG    "demo"

typedef struct {

} Demo;

JNIEXPORT jstring JNICALL
Java_pl_droidsonroids_ndkdemo_Demo_getHelloWorld(JNIEnv *env, jobject instance) {
    __android_log_print(ANDROID_LOG_FATAL, LOG_TAG, "hello %s %p", "world", &instance);
    return (*env)->NewStringUTF(env, "hello world");
}

JNIEXPORT jlong JNICALL
Java_pl_droidsonroids_ndkdemo_Demo_init(JNIEnv *env, jobject instance) {
    return (jlong) malloc(sizeof(Demo));
}

JNIEXPORT void JNICALL
Java_pl_droidsonroids_ndkdemo_Demo_release__J(JNIEnv *env, jobject instance, jlong ptr) {
    free((void *) ptr);
}