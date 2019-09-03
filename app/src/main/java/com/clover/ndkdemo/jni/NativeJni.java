package com.clover.ndkdemo.jni;

public class NativeJni {

    static {
        System.loadLibrary("native-lib");
    }

    public String key = "jason";

    public native String getStringFormCPlus();

    public native String loadStringToCPlus(String str);

}
