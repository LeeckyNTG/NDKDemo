package com.clover.ndkdemo.bean;

import android.util.Log;

public class Man extends Human {

    private static final String TAG = "Man";

    @Override
    public void sayHi() {
        Log.i(TAG, "sayHi: 男人打招呼！");
    }
}
