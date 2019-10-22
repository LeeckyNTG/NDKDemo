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

long get_file_size(const char *path) {
    FILE *fp = fopen(path, "rb");
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
}



/**
 * 文件
 * @param env
 * @param clazz
 * @param path_jstr
 * @param path_pattern_jstr
 * @param file_num
 */
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

    //获取文件大小
    int file_size = get_file_size(path);
    FILE *fpr = fopen(path, "rb");
    //可以整除
    if (file_size % file_num == 0) {
        LOGD("可以整除,file_size：%d", file_size);
        //单个文件大小
        int part = file_size / file_num;
        //逐一写入子文件中
        for (int i = 0; i < file_num; ++i) {
            LOGD("写入文件,file_num：%d，patches：%s", i + 1, patches[i]);
            FILE *fpw = fopen(patches[i], "wb");
            for (int j = 0; j < part; ++j) {
                //边读边写
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
        }
    } else {
        //不整除
        LOGD("不可以整除,file_size：%d", file_size);
        int part = file_size / (file_num - 1);
        //逐一写入子文件中
        for (int i = 0; i < file_num - 1; ++i) {
            LOGD("写入文件,file_num：%d，patches：%s", i + 1, patches[i]);
            FILE *fpw = fopen(patches[i], "wb");
            for (int j = 0; j < part; ++j) {
                //边读边写
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
        }
        //最后一个文件
        FILE *fpw = fopen(patches[file_num - 1], "wb");
        for (int i = 0; i < file_size % (file_num - 1); ++i) {
            //边读边写
            fputc(fgetc(fpr), fpw);
        }
        fclose(fpw);
    }

    //关闭总文件
    fclose(fpr);

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
Java_com_clover_file_1patch_jni_FileUtils_patch(JNIEnv *env, jclass clazz, jstring path_jstr,
                                                jstring path_pattern_jstr,
                                                jint file_num) {
    // TODO: implement patch()
    const char *merge_path = (*env)->GetStringUTFChars(env, path_jstr, NULL);
    const char *path_pattern = (*env)->GetStringUTFChars(env, path_pattern_jstr, NULL);

    LOGD("文件合并：%s", merge_path);

    char **patches = (malloc(sizeof(char *) * file_num));

    for (int i = 0; i < file_num; ++i) {
        patches[i] = malloc(sizeof(char) * 100);
        //元素赋值
        sprintf(patches[i], path_pattern, (i + 1));
        LOGD("文件合并子文件名：%s", patches[i]);
    }

    //写入文件
    FILE *fpw = fopen(merge_path, "wb");

    for (int i = 0; i < file_num; ++i) {
        //获取子文件大小
        int file_size = get_file_size(patches[i]);
        FILE *fpr = fopen(patches[i], "rb");
        for (int j = 0; j < file_size; ++j) {
            fputc(fgetc(fpr),fpw);
        }
        fclose(fpr);
    }

    //释放
    int i = 0;
    for(; i < file_num; i++){
        free(patches[i]);
    }
    free(patches);

    (*env)->ReleaseStringUTFChars(env,path_pattern_jstr,path_pattern);
    (*env)->ReleaseStringUTFChars(env,path_jstr,merge_path);


}