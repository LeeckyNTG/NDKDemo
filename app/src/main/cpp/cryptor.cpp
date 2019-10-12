//
// Created by Clover on 2019/9/30.
//

#include <jni.h>
#include <string>
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>

#define LOG_TAG "CRYPTOR"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


char password[] = "clover9999";


extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_Cryptor_strTest(JNIEnv *env, jobject thiz, jstring normal_path,
                                            jstring decrypt_path) {
    // TODO: implement strTest()
    const char *normal_path_chars = env->GetStringUTFChars(normal_path, JNI_FALSE);
    const char *crypt_path_chars = env->GetStringUTFChars(decrypt_path, JNI_FALSE);

    const char *str_chars = env->GetStringUTFChars(normal_path, JNI_FALSE);

    printf("normal_path_chars:%s", normal_path_chars);
    printf("crypt_path_chars:%s", crypt_path_chars);

}


/**
 * 加密
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_Cryptor_crypt(JNIEnv *env, jobject thiz, jstring normal_path,
                                          jstring crypt_path) {
    //jstring转char *

    jboolean isCopy = NULL;
    const char *normal_path_chars = env->GetStringUTFChars(normal_path, &isCopy);
    //判断是否复制了
    if (isCopy) {

    }
    const char *crypt_path_chars = env->GetStringUTFChars(crypt_path, NULL);

    //打开文件
    FILE *normal_fp = fopen(normal_path_chars, "rb");
    FILE *crypt_fp = fopen(crypt_path_chars, "wb");

    //一次读一个字节
    int ch;
    int i = 0; //循环使用密码中的字母进行异或运算
    int pwd_len = strlen(password);
    while ((ch = fgetc(normal_fp)) != EOF) {
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }
    env->ReleaseStringChars(normal_path, reinterpret_cast<const jchar *>(normal_path_chars));
    env->ReleaseStringChars(crypt_path, reinterpret_cast<const jchar *>(crypt_path_chars));
    //关闭文件流
    fclose(crypt_fp);
    fclose(normal_fp);
}


/**
 * 解密
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_Cryptor_decrypt(JNIEnv *env, jobject thiz, jstring normal_path,
                                            jstring decrypt_path) {

    //jstring转char *

    const char *normal_path_chars = env->GetStringUTFChars(normal_path, NULL);
    const char *decrypt_path_chars = env->GetStringUTFChars(decrypt_path, NULL);

    //打开文件
    FILE *normal_fp = fopen(normal_path_chars, "rb");
    FILE *decrypt_fp = fopen(decrypt_path_chars, "wb");

    //一次读一个字节
    int ch;
    int i = 0; //循环使用密码中的字母进行异或运算
    int pwd_len = strlen(password);
    while ((ch = fgetc(normal_fp)) != EOF) {
        fputc(ch ^ password[i % pwd_len], decrypt_fp);
        i++;
    }
    env->ReleaseStringChars(normal_path, reinterpret_cast<const jchar *>(normal_path_chars));
    env->ReleaseStringChars(decrypt_path, reinterpret_cast<const jchar *>(decrypt_path_chars));
    //关闭文件流
    fclose(decrypt_fp);
    fclose(normal_fp);
}