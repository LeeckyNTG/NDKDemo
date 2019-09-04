package com.clover.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.clover.ndkdemo.jni.NativeJni;

import java.util.Date;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

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

    }
}
