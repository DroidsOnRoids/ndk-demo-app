#include<jni.h>
#include<stdlib.h>
#include <android/log.h>

#define  LOG_TAG    "demo"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

typedef struct {

} Demo;

JNIEXPORT jstring JNICALL
Java_pl_droidsonroids_ndkdemo_Demo_getHelloWorld(JNIEnv *env, jobject instance) {
    jclass clazz = (*env)->GetObjectClass(env, instance);
    jmethodID methodID = (*env)->GetMethodID(env, clazz, "getHash", "()I");
    jint hash = (*env)->CallIntMethod(env, instance, methodID);
    LOGE("hash %d", hash);
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