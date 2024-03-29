package com.clover.ndkdemo.jni;

import android.util.Log;

import com.clover.ndkdemo.bean.Human;
import com.clover.ndkdemo.bean.Man;

import java.util.Date;
import java.util.Random;
import java.util.UUID;

public class NativeJni {

    private static final String TAG = "NativeJni";

    static {
        System.loadLibrary("native-lib");
    }

    public String key = "jason";

    public static int count = 9;

    public Human man = new Man();


    public native String getStringFormCPlus();

    public native String accessField(String str);

    public native void accessStaticField();

    public native void accessMethod();

    public native void accessStaticMethod();

    public native Date accessConstructor();

    public native void accessNonvirtualMethod();

    public native String chineseChars(String str);

    public native void giveArray(int [] arrays);

    public native int [] getArray(int len);

    public native void localRef();

    public native void createGlobalRef();

    public native String getGlobalRef();

    public native void deleteGlobalRef();

    public native void exeception();

    public native void cached();

    public native void bytesToInt8s(byte [] bytes);

    public native void byteToInt8();

    public int getRandomInt(int max) {
        Log.i(TAG, "getRandomInt: 执行了");
        return new Random().nextInt(max);
    }

    public static String getUUID(){

        String uuid = UUID.randomUUID().toString();

        new Date();

        return uuid;
    }

}
