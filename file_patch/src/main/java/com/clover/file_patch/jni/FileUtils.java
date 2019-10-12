package com.clover.file_patch.jni;

public class FileUtils {

    static {
        System.loadLibrary("file_utils");
    }

    /**
     * 文件拆分
     *
     * @param path
     * @param count
     */
    public native static void diff(String path,String path_pattern, int count);

    /**
     * 文件合并
     *
     * @param path
     * @param count
     */
    public native static void patch(String path, int count);

}
