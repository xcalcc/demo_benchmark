package poc.mx_poc;

public class mx_nocatch {
    mx_nothrow obj;

    public void call(String s) {
        String bizNo = obj.getSuccessLoanBizNoByMxNo(s);
        bizNo += bizNo.toLowerCase();
        bizNo += bizNo.toUpperCase();
    }
}
