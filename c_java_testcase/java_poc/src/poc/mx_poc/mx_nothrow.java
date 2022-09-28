package poc.mx_poc;

interface ScfpmMxLoanAppMapper {
    String getSuccessLoanBizNoByMxNo(String mxNo);
}

class StringUtils {
    public static boolean isBlank(String nizno) {
        return true;
    }
}

class TeslaApplicationException extends RuntimeException {
    public TeslaApplicationException(String s) {
        super(s);
    }
}

public class mx_nothrow {
    private ScfpmMxLoanAppMapper mxLoanAppMapper;
    public String getSuccessLoanBizNoByMxNo(String mxNo) {
        String bizNo = mxLoanAppMapper.getSuccessLoanBizNoByMxNo(mxNo);
        if (StringUtils.isBlank(bizNo)) {
            throw new TeslaApplicationException("loan.bizNo.notfound");
        }
        /* ... */
        return bizNo;
    }
}
