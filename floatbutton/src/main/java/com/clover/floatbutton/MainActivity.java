package com.clover.floatbutton;

import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                byte[] bytes_1 = {0, 0, 0, 1, 65, -16, 2, -94, 121, 59, -41, 39, 127, -109, -35, 114, 93, -1,
                        9, 111, -17, 124, -101, -21, -82, 31, 4, 119, -36, -87, -14, -9, -82, 19, -17, 98,
                        -21, -101, -35, 113, 59, -3, -3, -17, -7, -81, -70, -30, 47, -5, -82, -119, 40, 91,
                        -108, -69, -4, -67, -2, -91, 2, -121, -86, 95, -110, -1, -53, -33, -22, 122, 78, 93,
                        0, -1, 39, 127, -123, 119, -5, -82, -1, 93, 75, 124, -69, -2, 107, -1, 9, -17, -65,
                        -14, 119, -82, 109, -15, -36, -37, -2, 69, 98, -41, 109, -17, -16, 69, -33, 23, -62,
                        93, -9, -41, 47, -65, -87, -45, -28, -33, 93, -17, -82, -89, 79, -81, 61, 112, 69, -17,
                        -86, -28, -9, 92, 36, -76, 7, -34, -71, -88, 15, -5, -10, -68, 37, -39, -5, 11, -53, 64,
                        -24, 14, -72, -83, -98, -64, -6, -17, 127, -35, -121, -4, 94, -64, -3, 14, -71, -69, -55,
                        -33, 64, 127, 37, -127, -1, 4, 62, -127, -12, -100, -76, 63, -30, 118, 15, -17, -28, -95,
                        -1, 9, 81, -48, 14, -1, -55, 79, -5, -93, -2, 77, 1, -2, 111, 95, 123, 3, -3, -24, 15, 39,
                        8, -67, -10, 3, -17, -8, 38, -65, 126, 112, 95, 4, -69, -17, -50, -110, -9, -66, 43, -109,
                        -80, 127, 39, -72, -114, -121, 65, 55, 40, -5, -21, -110, -17, -8, 46, -17, -65, -33,
                        47, 123, -27, -9, 92, 90, 67, -3, 1, -101, -126, 77, -13, -107, 117, -22, -17, -79, -33,
                        9, 122, 3, -77, -4, 39, 95, -93, -7, 58, 7, -15, 30, -57, 124, -4, -35, -2, 59, -95, -19,
                        -39, -24, 15, -30, -75, -41, -8, 79, 71, -96, 62, -72, 33, -20, -8, -33, 8, -48, 31, 67, -6,
                        -41, 14, 123, 3, 95, -22, -72, -82, -105, 67, -5, 123, -41, 119, -33, -53, -17, -22, 122, 78,
                        47, -67, -7, 56, 36, -17, -126, 43, -110, -126, -25, -24, 83, -55, -41, -91, -28, 22, -17,
                        -82, 27, -65, 93, 63, -82, 8, -73, -32, -66, 93, -1, 47, 122, -27, 93, 26, -31, 45,
                        -101, 31, -96, 63, 47, 67, -82, 110, -73, -51, -40, 11, -17, 125, 114, -20, -11, -62,
                        126, -58, -57, -41, 118, 15, -7, 125, 13, 112, -105, 123, 61, -102, -26, -39, -2, 77,
                        -98, -69, -23, 124, -106, 63, -32, -93, -83, -128, -67, -33, 8, 80, 11, -24, 7, -82,
                        -71, -67, 125, 125, 124, 54, -5, -81, 79, -3, -9, -7, 59, -4, 18, -9, -9, -17, -118,
                        -17, -17, -31, 46, -5, -2, 94, -1, 39, 121, 58, 25, -33, 40, -35, 0, -2, 91, -18, 47,
                        -105, 127, -55, 126, 78, 106, 15, -66, -3, -4, -37, -21, -110, -3, 114, 95, -82, 93, -1,
                        21, 127, 127, -55, 127, -21, -27, 114, 119, -8, 74, -1, -70, -26, -33, 93, -17, -7, 61,
                        -58, -12, 76, 34, 59, 45, -1, 23, -18, -17, -82, 91, -1, 126, -2, 8, -5, -6, -71, 61, 0,
                        -4, -98, -17, -105, -67, 114, -33, -82, 122, -33, -1, 45, -1, -114, -33, -65, 64, -17, -32,
                        -65, -34, -123, -85, 127, -3, -5, -66, -9, -58, 119, -34, 110, 107, -1, 39, 98, -5, -65, 92,
                        -41, -2, -9, -4, 17, -5, -63, -14, 95, -66, 19, -12, 2, 122, 95, 47, 119, -9, -17, -17, 127,
                        -35, -33, -14, 123, -7, 125, -4, -69, -21, -66, -1, 53, -1, -124, -69, -9, -8, -21, -9, -17,
                        -41, 9, -5, -9, 92, -73, -2, -72, 87, 4, -9, -9, -5, -32, -106, -3, -1, 124, -98, -21, -105,
                        -67, 114, -6, 11, -53, -66, -8, -69, -9, -2, 8, 109, -14, -33, 38, -6, -28, -65, 124, -98, -2,
                        35, 126, -1, -101, -67, 112, -97, 127, 127, 125, -17, -124, -17, -10, 41, 56, 75, -33, 65,
                        125, -5, -82, 35, -65, 127, -69, -66, 43, -124, -9, -9, -7, 47, -33, 19, -18, -1, -53, -18,
                        -7, 111, -4, 37, -48, 9, -5, -7, -69, -3, -17, -8, 67, -67, -9, 127, -26, -17, 124, 17, -10,
                        -67, -14, 119, -8, 34, -33, 42, 124, -37, -2, 110, -11, -35, -1, -86, 80, -13, 119, -7, 59,
                        -4, 71, -67, -1, 53, 9, -1, 23, -66, -1, -35, -1, -65, 114, 115, 123, -7, 61, -4, 39, -17,
                        -33, -51, -33, -27, -65, 92, -98, -21, -109, 127, -51, -33, -28, -65, 124, -69, -21,
                        -86, 80, -14, 119, -7, 111, -4, -98, -2, 35, -34, -6, -31, 46, -9, -2, 95, 127, 38, -1,
                        -69, -1, 9, 88, 11, -17, 92, -105, -21, -120, -9, 126, -69, -24, 63, -101, -69, -82, 95,
                        113, 124, -101, -17, -101, -65, -60, -17, -33, -15, 61, -5, -4, -98, -2, 21, -9, -34, -69,
                        -1, -51, -65, -30, 59, -5, -7, 119, -53, -59, -5, -65, 92, 23, 111, -9, -22, -31, -37, -9,
                        -65, 122, -33, -1, 125, -33, -53, -33, -22, 90, -72, 46, -65, -66, -105, -22, 90, 22, -32,
                        -111, 118, 125, -14, -33, -66, 19, -10, 61, -100, -100, 75, -65, -35, 114, 123, -82, 79, 117,
                        -53, 126, -7, 61, -4, -67, -2, 109, -1, 54, -6, -17};

                for (int i = 0; i < bytes_1.length; i++) {
                    System.out.println("byte-i->" + i + "------data->" + bytes_1[i]);
                }
            }
        });


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
