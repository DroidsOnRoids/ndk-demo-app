#include<jni.h>

JNIEXPORT jstring JNICALL
Java_pl_droidsonroids_ndkdemo_Demo_getHelloWorld(JNIEnv *env, jobject object) {
	return (*env)->NewStringUTF(env, "hello world");
}