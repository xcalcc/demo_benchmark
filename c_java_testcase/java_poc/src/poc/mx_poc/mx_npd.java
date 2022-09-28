package poc.mx_poc;

import java.util.Map;
import java.util.HashMap;

class CustomerInfoVO {
    String getUniSociCrdtCode() {
        return "";
    }
}

interface MxSignedDetail {
    String getIssueCustNo();
    void setIssueUniSociCrdtCode(String code);
}

class BusinessException extends RuntimeException {
    public BusinessException(String s) {
        super(s);
    }
}

interface Service {
    Map<String, Object> execute(Map<String, Object> m);
}

class JSONUtils {
    public static String toJSONString(Object s) {
        return s.toString();
    }

    public static CustomerInfoVO parse(String json, Class<?> clazz) {
        return new CustomerInfoVO();
    }
}

class MxBizAppService {

}

public class mx_npd {
    private Service queryBusinessEntityByCustNo;
    private mx_npd mxBizAppService;
    private MxSignedDetail mxSignedDetail;
    
    public final MxSignedDetail getMxDetail(String mxNo) {
        // did not check result, if return is null 
        // use of customerInfoVOs is NPD in the next statement
        CustomerInfoVO customerInfoVOs = mxBizAppService.getCurrentUserInfo(mxSignedDetail.getIssueCustNo());
        
        mxSignedDetail.setIssueUniSociCrdtCode(customerInfoVOs.getUniSociCrdtCode());
        return mxSignedDetail;
    }
    
    
    public final CustomerInfoVO getCurrentUserInfo(String custNo) {
            Map<String, Object> paramMap = new HashMap<String, Object>();
            paramMap.put("custNo", custNo);
            Map<String, Object> outputs = this.queryBusinessEntityByCustNo.execute(paramMap);
            Map<String, Object> returnCode = (Map<String, Object>) outputs.get("returnCode");
            if (!returnCode.get("type").equals("S")) {
                throw new BusinessException((String) returnCode.get("message"));
            }
            //
            if (outputs.get("result") == null) {
                return null;
            }
            String resultJson = JSONUtils.toJSONString(outputs.get("result"));
            CustomerInfoVO customerInfo = JSONUtils.parse(resultJson, CustomerInfoVO.class);
            return customerInfo;
    }
}
