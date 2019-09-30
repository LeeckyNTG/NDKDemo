#include <jni.h>
#include <string>
#include <android/log.h>
#include <stdlib.h>

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
    jclass cls = env->GetObjectClass(thiz);

    jfieldID fid = env->GetFieldID(cls, "man", "Lcom/clover/ndkdemo/bean/Human;");

    jobject human_obj = env->GetObjectField(thiz, fid);

    //执行sayHi方法
    jclass human_cls = env->FindClass("com/clover/ndkdemo/bean/Human");
    jmethodID human_mid = env->GetMethodID(human_cls, "sayHi", "()V");

    env->CallObjectMethod(human_obj, human_mid);
    //调用父类方法
    env->CallNonvirtualObjectMethod(human_obj, human_cls, human_mid);

    return;

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_chineseChars(JNIEnv *env, jobject thiz, jstring str) {
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


int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}


/**
 * 传入数组
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_giveArray(JNIEnv *env, jobject thiz, jintArray arrays) {

    //获取jint数组指针
    jint *elements = env->GetIntArrayElements(arrays, NULL);
    //获取数组长度
    int arr_len = env->GetArrayLength(arrays);
    //排序
    qsort(elements, arr_len, sizeof(jint), compare);
    //同步
    env->ReleaseIntArrayElements(arrays, elements, JNI_COMMIT);
    return;
}

/**
 * 返回数组
 */
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_getArray(JNIEnv *env, jobject thiz, jint len) {

    jintArray jint_arr = env->NewIntArray(len);
    jint *element = env->GetIntArrayElements(jint_arr, NULL);

    for (int i = 0; i < len; ++i) {
        element[i] = i;
    }

    //同步
    env->ReleaseIntArrayElements(jint_arr, element, JNI_COMMIT);
    return jint_arr;
}

/**
 * 局部引用，通过DeleteRef手动释放对象
 * 1.访问一个很大的java对象，使用完之后还要进行负责的耗时操作
 * 2.创建了大量的局部引用，占用太多的内存时
 *
 * 循环创建数组
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_localRef(JNIEnv *env, jobject thiz) {
    // TODO: implement localRef()
    for (int i = 0; i < 5; ++i) {
        jclass cls = env->FindClass("java/util/Date");
        jmethodID constructor_mid = env->GetMethodID(cls, "<init>", "()V");
        jobject obj = env->NewObject(cls, constructor_mid);

        /**此处省略业务处理代码*/

        /**通知垃圾回收这些对象*/
        env->DeleteLocalRef(obj);
    }

}


/**
 * 全局引用
 * 可以在多个方法中使用
 */



jstring global_str = NULL;

/**
 * 创建全局变量
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_createGlobalRef(JNIEnv *env, jobject thiz) {
    // TODO: implement createGlobalRef()

    jstring obj = env->NewStringUTF("jni development is powerful!");
    global_str = static_cast<jstring>(env->NewGlobalRef(obj));
}

/**
 * 获取全局变量
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_getGlobalRef(JNIEnv *env, jobject thiz) {
    // TODO: implement getGlobalRef()
    return global_str;
}

/**
 * 释放全局变量
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_deleteGlobalRef(JNIEnv *env, jobject thiz) {
    // TODO: implement deleteGlobalRef()
    env->DeleteGlobalRef(global_str);
}

/**
 * 异常处理
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_exeception(JNIEnv *env, jobject thiz) {
    // TODO: implement exeception()
    jclass cls = env->FindClass("java/lang/String");
    jfieldID fid = env->GetFieldID(cls, "key", "Ljava/lang/String;");
    //检查是否发生异常
    jthrowable exception = env->ExceptionOccurred();

    if (exception != NULL) {
        //让java代码继续运行
        //清空异常
        env->ExceptionClear();
    }

    //人为抛出异常给java处理
    jclass new_exc_cls = env->FindClass("java/lang/Exception");
    env->ThrowNew(new_exc_cls, "异常");

}


/**
 * 缓存策略
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_cached(JNIEnv *env, jobject thiz) {
    // TODO: implement cached()

    jclass clz = env->GetObjectClass(thiz);

    /**
     * 获取fieldID只获取一次
     * 局部静态变量,会一直存储到内存里面直到程序结束才销毁
     */
    static jfieldID key_id = NULL;

    if (key_id == NULL) {
        key_id = env->GetFieldID(clz, "key", "Ljava/lang/String;");

        LOGD("----------------GetFieldID-------------------\n");
    }


}

extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_bytesToInt8s(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    // TODO: implement bytesToInt8s()

    jbyte *elements = env->GetByteArrayElements(bytes, NULL);

    for (int i = 0; i < sizeof(elements); ++i) {
        LOGD("---Java_com_clover_ndkdemo_jni_NativeJni_byteToInt8---++++%d", elements[i]);
    }

    LOGD("------------------------------------------------");

    uint8_t *uint8_char = reinterpret_cast<uint8_t *>(elements);
    for (int i = 0; i < sizeof(uint8_char); ++i) {
        LOGD("---Java_com_clover_ndkdemo_jni_NativeJni_byteToInt8---++++%d", uint8_char[i]);
    }

}

extern "C"
JNIEXPORT void JNICALL
Java_com_clover_ndkdemo_jni_NativeJni_byteToInt8(JNIEnv *env, jobject thiz) {
    // TODO: implement byteToInt8()

    int8_t a = -2;

    uint8_t b = a;

    LOGD("---Java_com_clover_ndkdemo_jni_NativeJni_byteToInt8---%d", b);
}

extern "C"
JNIEXPORT void JNICALL
Java__NativeJni_ByteArray(JNIEnv *env, jobject thiz, jbyteArray bytes) {
    // TODO: implement ByteArray()
}