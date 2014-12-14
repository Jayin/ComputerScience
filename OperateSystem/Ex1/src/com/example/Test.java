package com.example;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;

/**
 * Created by jayin on 14/12/1.
 */
public class Test {
    public static void main(String[] args) {
        String s = "s=1&r&c=&b=1";
        String[] ss = s.split("&");
        for (String t : ss) {

            if (t.indexOf('=') != -1) {
                String name = t.split("=")[0];
                String value = null;
                try {
                    value = URLDecoder.decode(t.split("=")[1], "UTF-8");
                } catch (UnsupportedEncodingException e) {
                    value = t.split("=")[1];
                } catch (IndexOutOfBoundsException e) {
                    //处理这种情况 ?a=1&b=&c=2
                    value = "";
                }
                System.out.println(name + " : " + value);
            }

        }
    }
}
