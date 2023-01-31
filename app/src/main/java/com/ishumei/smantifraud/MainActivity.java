package com.ishumei.smantifraud;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Locale;

public class MainActivity extends AppCompatActivity {
    TextView mInfo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mInfo = findViewById(R.id.detect_info);
    }

    public void detect(View view) {
        SmAntiFraud saf = new SmAntiFraud();
        mInfo.setText(String.format(Locale.US, "ROOT: %s\n\nHOOK: %s", saf.isRoot(), saf.isHook()));
    }
}