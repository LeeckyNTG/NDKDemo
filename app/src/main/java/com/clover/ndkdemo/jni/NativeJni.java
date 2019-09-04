package com.clover.ndkdemo.jni;

import android.util.Log;

import java.util.Random;
import java.util.UUID;

public class NativeJni {

    private static final String TAG = "NativeJni";

    static {
        System.loadLibrary("native-lib");
    }

    public String key = "jason";

    public static int count = 9;

    public native String getStringFormCPlus();

    public native String accessField(String str);

    public native void accessStaticField();

    public native void accessMethod();

    public native void accessStaticMethod();

    public int getRandomInt(int max) {
        Log.i(TAG, "getRandomInt: 执行了");
        return new Random().nextInt(max);
    }

    public static String getUUID(){

        String uuid = UUID.randomUUID().toString();

        return uuid;
    }

}
