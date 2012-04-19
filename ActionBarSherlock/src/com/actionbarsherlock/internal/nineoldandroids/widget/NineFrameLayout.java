package com.actionbarsherlock.internal.nineoldandroids.widget;

import android.content.Context;
import android.os.Build;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.widget.FrameLayout;

import com.actionbarsherlock.internal.nineoldandroids.view.animation.AnimatorProxy;
import com.actionbarsherlock.internal.utils.UtilityWrapper;

import java.lang.reflect.Method;

public class NineFrameLayout extends FrameLayout {
    private final AnimatorProxy mProxy;
    private static Method superSetAlphaMethod = null;
    private static Method superGetAlphaMethod = null;
    private static Method superGetTranslationYMethod = null;
    private static Method superSetTranslationYMethod = null;
    private static Method superOnHoverEventMethod = null;

    public NineFrameLayout(Context context) {
        super(context);
        mProxy = AnimatorProxy.NEEDS_PROXY ? AnimatorProxy.wrap(this) : null;
        

        // Building compatibility
        Class<?> cls = getClass();
        if (!AnimatorProxy.NEEDS_PROXY && superGetAlphaMethod == null) {
            superGetAlphaMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "getAlpha");
            superSetAlphaMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "setAlpha");
            superGetTranslationYMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "getTranslationY");
            superSetTranslationYMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "setTranslationY");

        }

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH
                && superOnHoverEventMethod == null) {
            superOnHoverEventMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "onHoverEvent");
        }

    }
    public NineFrameLayout(Context context, AttributeSet attrs) {
        super(context, attrs);
        mProxy = AnimatorProxy.NEEDS_PROXY ? AnimatorProxy.wrap(this) : null;
    }
    public NineFrameLayout(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        mProxy = AnimatorProxy.NEEDS_PROXY ? AnimatorProxy.wrap(this) : null;
    }

    @Override
    public void setVisibility(int visibility) {
        if (mProxy != null) {
            if (visibility == GONE) {
                clearAnimation();
            } else if (visibility == VISIBLE) {
                setAnimation(mProxy);
            }
        }
        super.setVisibility(visibility);
    }

    public float getAlpha() {
        if (AnimatorProxy.NEEDS_PROXY) {
            return mProxy.getAlpha();
        } else {
            Float res = (Float) UtilityWrapper.safelyInvokeMethod(superGetAlphaMethod, this);
            if(res != null) {
                return res;
            }
        }
        return 0.0f;
    }
    
    public void supportSetAlpha(float alpha) {
        if (AnimatorProxy.NEEDS_PROXY) {
            mProxy.setAlpha(alpha);
        } else {
            UtilityWrapper.safelyInvokeMethod(superSetAlphaMethod, this, alpha);
        }
    }

    public void setAlpha(float alpha) {
        supportSetAlpha(alpha);
    }
    
    public float getTranslationY() {
        if (AnimatorProxy.NEEDS_PROXY) {
            return mProxy.getTranslationY();
        } else {
            Float res = (Float) UtilityWrapper.safelyInvokeMethod(superGetTranslationYMethod, this);
            if(res != null) {
                return res;
            }
            return 0.0f;
        }
    }
    
    public void supportSetTranslationY(float translationY) {
        if (AnimatorProxy.NEEDS_PROXY) {
            mProxy.setTranslationY(translationY);
        } else {
            UtilityWrapper.safelyInvokeMethod(superSetTranslationYMethod, this, translationY);
        }
    }

    public void setTranslationY(float translationY) {
        supportSetTranslationY(translationY);
    }
    
    public boolean onHoverEvent(MotionEvent event) {
        if(superOnHoverEventMethod != null) {
            UtilityWrapper.safelyInvokeMethod(superOnHoverEventMethod, this, event);
        }
        return true;
    }
}
