package com.clover.ndkdemo.jni;

public class Cryptor {

    static {
        System.loadLibrary("cryptor");
    }

    public native void crypt(String normal_path, String crypt_path);

    public native void decrypt(String normal_path, String decrypt_path);

    public native void strTest(String normal_path, String decrypt_path);

}
