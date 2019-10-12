//
// Created by Clover on 2019/10/12.
//
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>

#define LOG_TAG "FILE_UTILS"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


JNIEXPORT void JNICALL
Java_com_clover_file_1patch_jni_FileUtils_diff(JNIEnv *env, jclass clazz, jstring path_jstr,
                                               jstring path_pattern_jstr,
                                               jint file_num) {
    const char *path = (*env)->GetStringUTFChars(env, path_jstr, NULL);
    const char *path_pattern = (*env)->GetStringUTFChars(env, path_pattern_jstr, NULL);

    LOGD("文件拆分：%s", path);

    char **patches = (malloc(sizeof(char *) * file_num));

    for (int i = 0; i < file_num; ++i) {
        patches[i] = malloc(sizeof(char) * 100);
        //元素赋值
        sprintf(patches[i], path_pattern, (i + 1));
        LOGD("文件拆分子文件名：%s", patches[i]);
    }
    //不断读取path文件，循环写入file——num个文件中


    //释放
    for (int i = 0; i < file_num; ++i) {
        patches[i] = malloc(sizeof(char) * 100);
        //元素释放
        free(patches[i]);
    }
    free(patches);

    (*env)->ReleaseStringChars(env, path_jstr, path);
    (*env)->ReleaseStringChars(env, path_pattern_jstr, path_pattern);
}

JNIEXPORT void JNICALL
Java_com_clover_file_1patch_jni_FileUtils_patch(JNIEnv *env, jclass clazz, jstring path,
                                                jint count) {
    // TODO: implement patch()
    LOGD("文件合并");
}