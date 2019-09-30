package com.clover.ndkdemo.activity;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.Nullable;

import com.clover.ndkdemo.R;
import com.clover.ndkdemo.jni.Cryptor;

import java.io.File;

public class FileCryptorActivity extends Activity {

    Cryptor cryptor = null;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_file_cryptor);
        cryptor = new Cryptor();
    }

    public void click(View view) {
        switch (view.getId()) {
            case R.id.btn_crypt:
                crypt();
                break;
            case R.id.btn_decrypt:
                decrypt();
                break;
        }
    }

    /**
     * 加密
     */
    private void crypt() {
        String normal_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "img.jpg";
        String crypt_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "crypt_path.jpg";
        cryptor.crypt(normal_path, crypt_path);
        Toast.makeText(this, "加密完成", Toast.LENGTH_LONG).show();
    }

    /**
     * 解密
     */
    private void decrypt() {
        String normal_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "crypt_path.jpg";
        String decrypt_path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "decrypt_path.jpg";
        cryptor.decrypt(normal_path, decrypt_path);
        Toast.makeText(this, "解密完成", Toast.LENGTH_LONG).show();
    }


}
