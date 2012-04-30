package com.actionbarsherlock.internal.nineoldandroids.widget;

import android.content.Context;
import android.content.res.Configuration;
import android.os.Build;
import android.widget.HorizontalScrollView;
import com.actionbarsherlock.internal.nineoldandroids.view.animation.AnimatorProxy;
import com.actionbarsherlock.internal.utils.UtilityWrapper;

import java.lang.reflect.Method;

public class NineHorizontalScrollView extends HorizontalScrollView {
    private final AnimatorProxy mProxy;
    private static Method superSetAlphaMethod;
    private static Method superGetAlphaMethod;
    private static Method superOnConfigurationChangedMethod;

    public NineHorizontalScrollView(Context context) {
        super(context);
        mProxy = AnimatorProxy.NEEDS_PROXY ? AnimatorProxy.wrap(this) : null;
        loadStaticMethods();
    }
    
    private void loadStaticMethods() {
        // Building compatibility
        Class<?> cls = NineHorizontalScrollView.class;
        if (!AnimatorProxy.NEEDS_PROXY && superGetAlphaMethod == null) {
            superGetAlphaMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "getAlpha");
            superSetAlphaMethod = UtilityWrapper.safelyGetSuperclassMethod(cls, "setAlpha", float.class);
        }
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH
                && superOnConfigurationChangedMethod == null) {
            superOnConfigurationChangedMethod = UtilityWrapper.safelyGetSuperclassMethod(cls,
                    "onConfigurationChanged", Configuration.class);
        }
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

    public float supportGetAlpha() {
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
    
    /*
    protected void onConfigurationChanged(Configuration newConfig) {
        if(superOnConfigurationChangedMethod != null) {
            UtilityWrapper.safelyInvokeMethod(superOnConfigurationChangedMethod, this, newConfig);
        }
    }
    */
}
