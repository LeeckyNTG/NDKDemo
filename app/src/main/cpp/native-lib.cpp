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

/**
 * 访问构造方法
 */
extern "C"
JNIEXPORT jobject JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_accessConstructor(JNIEnv *env, jobject thiz) {
    // TODO: implement accessConstructor()

    LOGD("进入");

    jclass cls = env->FindClass("java/util/Date");

    if (cls == NULL) {
        LOGD("cls is null");
    } else {
        LOGD("cls is not null");
    }



    //<init> 构造方法的名称用这个
    jmethodID mid = env->GetMethodID(cls, "<init>", "()V");

    if (mid == NULL) {
        LOGD("mid is null");
    } else {
        LOGD("mid is not null");
    }

    //实例化对象
    jobject date_obj = env->NewObject(cls, mid);

    if (date_obj == NULL) {
        LOGD("date_obj is null");
    } else {
        LOGD("date_obj is not null");
    }


    //调用getTime()方法
    jmethodID get_time_mid = env->GetMethodID(cls, "getTime", "()J");

    if (get_time_mid == NULL) {
        LOGD("get_time_mid is null");
    } else {
        LOGD("get_time_mid is not null");
    }

    //date_obj--jobject
    jlong time = env->CallLongMethod(date_obj, get_time_mid);

    if (time == NULL) {
        LOGD("time is null");
    } else {
        LOGD("time is not null->%");
    }


    LOGD("time:%lld", time);

    return date_obj;


}

extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_accessNonvirtualMethod(JNIEnv *env, jobject thiz) {
    // TODO: implement accessNonvirtualMethod()

    jclass cls = env->GetObjectClass(thiz);

    jfieldID fid = env->GetFieldID(cls, "man", "Lcom/clover/ndkdemo/bean/Human;");

    jobject human_obj = env->GetObjectField(thiz, fid);

    //执行sayHi方法
    jclass human_cls = env->FindClass("com/clover/ndkdemo/bean/Human");
    jmethodID human_mid = env->GetMethodID(human_cls, "sayHi", "()V");

    env->CallObjectMethod(human_obj, human_mid);
    //调用父类方法
    env->CallNonvirtualObjectMethod(human_obj, human_cls, human_mid);


}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_chineseChars(JNIEnv *env, jobject thiz, jstring str) {
    // TODO: implement chineseChars()

    const char *str_chars = env->GetStringUTFChars(str, JNI_FALSE);

    LOGD("传入信息：%s", str_chars);


    char *re_chars = "老李家的兔崽子们";

    jstring re = env->NewStringUTF(re_chars);

    jclass cls = env->FindClass("java/lang/String");
    jmethodID mid = env->GetMethodID(cls, "<init>", "([BLjava/lang/String;)V");

    jbyteArray bytes = env->NewByteArray(strlen(re_chars));
    env->SetByteArrayRegion(bytes, 0, strlen(re_chars), reinterpret_cast<const jbyte *>(re_chars));

    jstring charsetName = env->NewStringUTF("UTF8");
    jstring strCode = static_cast<jstring>(env->NewObject(cls, mid, bytes, charsetName));

    return strCode;

}