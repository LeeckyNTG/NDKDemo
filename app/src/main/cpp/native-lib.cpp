#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "NDK_DOMO"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_getStringFormCPlus(JNIEnv *env, jobject thiz) {
    // TODO: implement getStringFormCPlus()
    return env->NewStringUTF("Hello from c plus...");
}


/**
 * 访问java的类属性
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_accessField(JNIEnv *env, jobject thiz, jstring str) {
    // TODO: implement accessField()

    //获取jclass
    jclass cls = env->GetObjectClass(thiz);

    //获取jfieldID
    jfieldID fid = env->GetFieldID(cls, "key", "Ljava/lang/String;");

    //获取key属性的值
    jstring jstr = static_cast<jstring>(env->GetObjectField(thiz, fid));

    //使用JNI_TRUE会报错
    const char *c_str = env->GetStringUTFChars(jstr, JNI_FALSE);

    char text[20] = "super ";
    strcat(text, c_str);

    jstring result = env->NewStringUTF(text);

    env->SetObjectField(thiz, fid, result);

    return result;
}

/**
 * 访问java的静态属性
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_accessStaticField(JNIEnv *env, jobject thiz) {
    // TODO: implement accessStaticField()
    //获取jclass
    jclass cls = env->GetObjectClass(thiz);
    //获取jfieldID
    jfieldID fid = env->GetStaticFieldID(cls, "count", "I");

    jint count = env->GetStaticIntField(cls, fid);
    count++;
    env->SetStaticIntField(cls, fid, count);
}

/**
 * 访问java的类方法
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_accessMethod(JNIEnv *env, jobject thiz) {
    // TODO: implement accessMethod()

    jclass cls = env->GetObjectClass(thiz);

    jmethodID mid = env->GetMethodID(cls, "getRandomInt", "(I)I");

    jint num = env->CallIntMethod(thiz, mid, 100);

    LOGD("产生的随机数为：%ld", num);
}


/**
 * 访问java的静态方法
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_accessStaticMethod(JNIEnv *env, jobject thiz) {
    // TODO: implement accessStaticMethod()

    jclass cls = env->GetObjectClass(thiz);

    jmethodID mid = env->GetStaticMethodID(cls, "getUUID", "()Ljava/lang/String;");

    jstring uuid = static_cast<jstring>(env->CallStaticObjectMethod(cls, mid));

    const char *uuid_str = env->GetStringUTFChars(uuid, JNI_FALSE);

    LOGD("uuid:%s", uuid_str);
}