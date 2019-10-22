package com.clover.file_patch;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Environment;
import android.view.View;

import com.clover.file_patch.jni.FileUtils;

import java.io.File;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void click(View view) {
        switch (view.getId()) {
            case R.id.btn_diff: {
                String normal_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "file_patch" + File.separatorChar + "JNI文件拆分.avi";
                String path_pattern = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "file_patch" + File.separatorChar + "JNI文件拆分" + File.separatorChar + "%d.avi";
                FileUtils.diff(normal_path, path_pattern, 20);
            }
            break;
            case R.id.btn_patch: {
                String normal_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "file_patch" + File.separatorChar + "JNI文件拆分_合并.avi";
                String path_pattern = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "file_patch" + File.separatorChar + "JNI文件拆分" + File.separatorChar + "%d.avi";
                FileUtils.patch(normal_path, path_pattern, 20);
            }
            break;
        }
    }
}
