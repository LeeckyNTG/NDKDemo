#include <jni.h>
#include <string>
#include <android/log.h>


#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_getStringFormCPlus(JNIEnv *env, jobject thiz) {
    // TODO: implement getStringFormCPlus()

    printf("进入函数Java_com_clover_ndkdemo_jni_NativeJni_getStringFormCPlus");
    return env->NewStringUTF("Hello from c plus...");


}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_loadStringToCPlus(JNIEnv *env, jobject thiz, jstring str) {
    // TODO: implement loadStringToCPlus()


    printf("进入函数");

    __android_log_print(0,"TAG","进入函数");

    //获取jclass
    jclass cls = env->GetObjectClass(thiz);

    if (cls == NULL){
        printf("cls null...");
    } else{
        printf("cls not null...");
    }

    //获取jfieldID
    jfieldID fid = env->GetFieldID(cls, "key", "Ljava/lang/String;");

    if (fid == NULL){
        printf("fid null...");
    } else{
        printf("fid not null...");
    }

    //获取key属性的值
    jstring jstr= static_cast<jstring>(env->GetObjectField(thiz, fid));

    const char *c_str = env->GetStringUTFChars(jstr,JNI_FALSE);
    char text[20] = "super ";
    strcat(text,c_str);

    jstring result = env->NewStringUTF(text);

    env->SetObjectField(thiz,fid,result);
}