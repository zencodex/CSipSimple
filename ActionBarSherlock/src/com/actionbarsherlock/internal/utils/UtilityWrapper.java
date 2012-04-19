/**
 * Copyright (C) 2010-2012 Regis Montoya (aka r3gis - www.r3gis.fr)
 * This file is part of ActionBarSherlock2.
 *
 *  CSipSimple is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  If you own a pjsip commercial license you can also redistribute it
 *  and/or modify it under the terms of the GNU Lesser General Public License
 *  as an android library.
 *
 *  CSipSimple is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ActionBarSherlock2.  If not, see <http://www.gnu.org/licenses/>.
 */

package com.actionbarsherlock.internal.utils;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewConfiguration;
import android.widget.PopupWindow;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public abstract class UtilityWrapper {

    private static UtilityWrapper instance;

    public static UtilityWrapper getInstance() {
        if (instance == null) {
            // TODO : dynamic package name here
            String className = "com.actionbarsherlock.internal.utils.Utility";
            if (Build.VERSION.SDK_INT >= 14) {
                className += "14";
            } else if (Build.VERSION.SDK_INT >= 11) {
                className += "11";
            } else if (Build.VERSION.SDK_INT >= 8) {
                className += "8";
            } else if (Build.VERSION.SDK_INT >= 7) {
                className += "7";
            } else {
                className += "4";
            }
            try {
                Class<? extends UtilityWrapper> wrappedClass = Class.forName(className).asSubclass(
                        UtilityWrapper.class);
                instance = wrappedClass.newInstance();
            } catch (Exception e) {
                throw new IllegalStateException(e);
            }
        }

        return instance;
    }
    
    public abstract void viewSetActivated(View view, boolean activated);
    
    public abstract boolean hasPermanentMenuKey(ViewConfiguration vcfg);
    
    public abstract void jumpDrawablesToCurrentState(View v);
    
    public abstract Drawable getActivityLogo(Context context);
    
    public abstract CharSequence stringToUpper(CharSequence text);
    
    public abstract PopupWindow buildPopupWindow(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes);

    public abstract void jumpToCurrentState(Drawable indeterminateDrawable);
    
    public abstract int resolveSizeAndState(int size, int measureSpec, int state);
    
    public abstract boolean isLongPressEvent(KeyEvent evt);
    
    public static Method safelyGetSuperclassMethod(Class<?> cls, String methodName) {
        try {
            return cls.getSuperclass().getDeclaredMethod(methodName);
        } catch (NoSuchMethodException e) {
            Log.e(cls.getCanonicalName(), "Impossible to get method " + methodName, e);
        }
        return null;
    }
    
    public static Object safelyInvokeMethod(Method method, Object receiver, Object... args) {
        try {
            return method.invoke(receiver, args);
        } catch (IllegalArgumentException e) {
            Log.e("Safe invoke fail", "Invalid args", e);
        } catch (IllegalAccessException e) {
            Log.e("Safe invoke fail", "Invalid args", e);
        } catch (InvocationTargetException e) {
            Log.e("Safe invoke fail", "Invalid args", e);
        }
        
        return null;
    }
}
