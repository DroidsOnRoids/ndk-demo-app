#include <jni.h>
#include <stdlib.h>
#include <pthread.h>
#include <android/log.h>

#define  LOG_TAG    "demo"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

typedef struct {

} Demo;

JavaVM *vm;
jobject globalInstance;

static void *doWork(void *unused) {
	JNIEnv *env;
	struct JavaVMAttachArgs args = {
			.group=NULL,
			.name="NativeWorker",
			.version = JNI_VERSION_1_6
	};
	(*vm)->AttachCurrentThread(vm, &env, &args);
	jclass clazz = (*env)->GetObjectClass(env, globalInstance);
	jmethodID methodID = (*env)->GetMethodID(env, clazz, "getHash", "()I");
	jint hash = (*env)->CallIntMethod(env, globalInstance, methodID);
	LOGE("hash %d", hash);
	(*vm)->DetachCurrentThread(vm);
	return NULL;
}

JNIEXPORT jstring JNICALL
Java_pl_droidsonroids_ndkdemo_Demo_getHelloWorld(JNIEnv *env, jobject instance) {
	globalInstance = (*env)->NewGlobalRef(env, instance);
	(*env)->GetJavaVM(env, &vm);
	pthread_t thread;
	pthread_create(&thread, NULL, doWork, NULL);
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