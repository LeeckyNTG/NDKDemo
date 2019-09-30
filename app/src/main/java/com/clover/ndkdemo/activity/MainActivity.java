package com.clover.ndkdemo.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.clover.ndkdemo.R;
import com.clover.ndkdemo.jni.NativeJni;

import java.util.Date;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//        nativeJni();

    }

    private void nativeJni() {

        NativeJni jni = new NativeJni();

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(jni.getStringFormCPlus());

        Log.i(TAG, "onCreate: key修改前->" + jni.key);
        jni.accessField(jni.key);
        Log.i(TAG, "onCreate: key修改前修改后->" + jni.key);

        Log.i(TAG, "onCreate: count修改前->" + NativeJni.count);
        jni.accessStaticField();
        Log.i(TAG, "onCreate: count修改后->" + NativeJni.count);

        jni.accessMethod();

        jni.accessStaticMethod();

        Date date = jni.accessConstructor();
        Log.i(TAG, "onCreate: java-time" + date.getTime());

        jni.accessNonvirtualMethod();

        String str = jni.chineseChars("老王家的小崽子");

        Log.i(TAG, "onCreate: 接受信息：" + str);

        int[] array = {87, 100, 56, 47, 12, 49, 53};

        jni.giveArray(array);

        for (int a : array) {
            System.out.println(a);
        }


        int[] arr = jni.getArray(20);
        for (int a : arr) {
            System.out.println(a);
        }


        System.out.println("----------------globalRef-------------------");
        jni.createGlobalRef();
        String globalStr = jni.getGlobalRef();
        System.out.println(globalStr);
        jni.deleteGlobalRef();
//        String globalStr1 = jni.getGlobalRef();
//        if (globalStr1 != null)
//            System.out.println(globalStr1);
//        else
//            System.out.println("global is null");

        try {
            jni.exeception();
        } catch (Exception e) {
            e.printStackTrace();
        }


        for (int i = 0; i < 10; i++) {
            jni.cached();
        }


        byte[] bytes = {-2, -127, 56, 89};

        jni.bytesToInt8s(bytes);

//        jni.byteToInt8();

    }


}
