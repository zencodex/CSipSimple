package com.actionbarsherlock.internal.nineoldandroids.view;

import android.content.Context;
import android.content.res.Configuration;
import android.os.Build;
import android.util.AttributeSet;
import android.view.ViewGroup;

import com.actionbarsherlock.internal.nineoldandroids.view.animation.AnimatorProxy;
import com.actionbarsherlock.internal.utils.UtilityWrapper;

import java.lang.reflect.Method;

public abstract class NineViewGroup extends ViewGroup {
    private final AnimatorProxy mProxy;
    private static Method superOnConfigurationChangedMethod;
    private static Method superGetAlphaMethod;
    private static Method superSetAlphaMethod;
    private static Method superGetTranslationXMethod;
    private static Method superSetTranslationXMethod;
    private static Method superGetTranslationYMethod;
    private static Method superSetTranslationYMethod;

    public NineViewGroup(Context context) {
        super(context);
        mProxy = AnimatorProxy.NEEDS_PROXY ? AnimatorProxy.wrap(this) : null;

        // Building compatibility
        Class<?> cls = getClass();
        if (!AnimatorProxy.NEEDS_PROXY && superGetAlphaMethod == null) {
            superGetAlphaMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "getAlpha");
            superSetAlphaMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "setAlpha");

            superGetTranslationXMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "getTranslationX");
            superSetTranslationXMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "setTranslationX");
            superGetTranslationYMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "getTranslationY");
            superSetTranslationYMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "setTranslationY");
        }
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH
                && superOnConfigurationChangedMethod == null) {
            superOnConfigurationChangedMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "onConfigurationChanged");
        }

    }
    public NineViewGroup(Context context, AttributeSet attrs) {
        super(context, attrs);
        mProxy = AnimatorProxy.NEEDS_PROXY ? AnimatorProxy.wrap(this) : null;
    }
    public NineViewGroup(Context context, AttributeSet attrs, int defStyle) {
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

    public float getTranslationX() {
        if (AnimatorProxy.NEEDS_PROXY) {
            return mProxy.getTranslationX();
        } else {
            Float res = (Float) UtilityWrapper.safelyInvokeMethod(superGetTranslationXMethod, this);
            if(res != null) {
                return res;
            }
            return 0.0f;
        }
    }
    public void setTranslationX(float translationX) {
        if (AnimatorProxy.NEEDS_PROXY) {
            mProxy.setTranslationX(translationX);
        } else {
            UtilityWrapper.safelyInvokeMethod(superSetTranslationXMethod, this, translationX);
        }
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
    public void setTranslationY(float translationY) {
        if (AnimatorProxy.NEEDS_PROXY) {
            mProxy.setTranslationY(translationY);
        } else {
            UtilityWrapper.safelyInvokeMethod(superSetTranslationYMethod, this, translationY);
        }
    }
    
    protected void onConfigurationChanged(Configuration newConfig) {
        if(superOnConfigurationChangedMethod != null) {
            UtilityWrapper.safelyInvokeMethod(superOnConfigurationChangedMethod, this, newConfig);
        }
    }
}
