package com.ishumei.smantifraud;

public class SmAntiFraud {

    // Used to load the 'smantifraud' library on application startup.
    static {
        System.loadLibrary("smsdk");
    }

    /**
     * A native method that is implemented by the 'smantifraud' native library,
     * which is packaged with this application.
     */
    public native boolean isRoot();
    public native boolean isHook();
}