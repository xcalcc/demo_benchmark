package poc.mx_poc;

import io.xc5.RBC_ENGINE;

class ScfpUser {

    public final void setLoginName(String loginName) {
        RBC_ENGINE.Rbc_assert(
            RBC_ENGINE.Pre_sanitized(RBC_ENGINE.Get_arg(1)), 888, "IDS03-J", "", 
            RBC_ENGINE.RULE_CATEGORY.CERT, "", 0
        );
    }
}

