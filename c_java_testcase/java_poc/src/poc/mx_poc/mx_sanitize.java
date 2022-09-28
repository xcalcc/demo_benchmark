package poc.mx_poc;

enum Constants {
    SCFP_USER_STATUS_6
}

class ScfpUser {
    String m;

    public final void setLoginName(String loginName) {
        m = loginName;
        m += loginName.toLowerCase();
        m += loginName.toUpperCase();
        m += loginName.concat("s");
    }

    public void setStatus(Constants c) {

    }
}

public class mx_sanitize {

    public final void ukeyBinding(String loginName) {

        ScfpUser scfpUser = new ScfpUser();
        scfpUser.setLoginName(loginName);
        scfpUser.setStatus(Constants.SCFP_USER_STATUS_6);
    }
}

