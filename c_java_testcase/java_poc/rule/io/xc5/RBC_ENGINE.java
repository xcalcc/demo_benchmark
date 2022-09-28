package io.xc5;
class RULE_INFO {

  private String _name;
  private long _err_code;
  private long _super_set;
  private int _category;
  private int _source;
  private String _err_msg;
  private String _suggest;

  public RULE_INFO(String name, long err_code, long sset, int category,
                    int source, String err_msg, String suggest) {
    _name = name;
    _err_code = err_code;
    _super_set = sset;
    _category = category;
    _source = source;
    _err_msg = err_msg;
    _suggest = suggest;
  }
  public String Get_name() { return _name; }
  public long Get_err_code() { return _err_code; }
  public long Get_super_set() { return _super_set; }
  public int Get_category() { return _category; }
  public int Get_source_lang() { return _source; }
  public String Get_err_msg() { return _err_msg; }
  public String Get_suggest() { return _suggest; }
};
class ASSESSMENT {

  private int _severity;
  private int _likelihood;
  private int _cost;
  private int _priority;
  private int _level;

  public ASSESSMENT(int severity, int likelihood, int cost,
                     int priority, int level) {
    _severity = severity;
    _likelihood = likelihood;
    _cost = cost;
    _priority = priority;
    _level = level;
  }
  public int Get_severity() { return _severity; }
  public int Get_likelihood() { return _likelihood; }
  public int Get_cost() { return _cost; }
  public int Get_priority() { return _priority; }
  public int Get_level() { return _level; }
};
class RULE {

  private long _id;
  private Object _bool_expr;
  private RULE_INFO _info;
  private ASSESSMENT _assessment;
  private boolean _scanned;
  private boolean _tracing;
  private boolean _enable;

  public RULE (long id, Object expr, RULE_INFO info,
                ASSESSMENT assess) {
    _id = id;
    _bool_expr = expr;
    _info = info;
    _assessment = assess;
    _scanned = false;
    _tracing = false;
    _enable = true;
  }
  public long Get_id() { return _id; }
  public Object Get_bool_expr() { return _bool_expr; }
  public RULE_INFO Get_rule_info() { return _info; }
  public ASSESSMENT Get_assessment() { return _assessment; }
  public boolean Get_scanned() { return _scanned; }
  public void Set_scanned(boolean s) { _scanned = s; }
  public boolean Get_tracing() { return _tracing; }
  public void Set_tracing(boolean t) { _tracing = t; }
  public boolean Get_enable() { return _enable; }
  public void Set_enable(boolean e) { _enable = e; }
  public void Print(Object fp) { return; }
};
public class RBC_ENGINE {

 
 
  public class RSC_KIND {
    public static final int NONE = 0;
    public static final int ALLOC = 2;
    public static final int LOCK = 5;
    public static final int FILE = 6;
  };
  public class RSC_STATUS {
    public static final int NONE = 0;
    public static final int CREATED = 1;
    public static final int READ = 2;
    public static final int MODIFIED = 3;
    public static final int USED = 4;
    public static final int DELETE = 5;
  };
  public class RULE_CATEGORY {
    public static final int USER = 0;
    public static final int BUILTIN = 1;
    public static final int CERT = 2;
  };
  public static void Rbc_assert(boolean cond, int errcode, String rule_name,
                                 String err_msg, int category, String suggest,
                                 long super_set) { return; };
  public static void Rbc_apply_rule( String rule_name) { return; };
  public static boolean Pre_sanitized(Object v) { return true; };
  public static boolean Pre_check(Object v, Object rsc, int kind, int status) { return true; };
  public static boolean Pre_check_value(Object v, String opr, Object value,
                                 Object rsc, int kind, int status) { return true; };
  public static boolean Pre_rsc_is_set_status(Object rsc, int kind, int status) { return true; };
  public static boolean Pre_call( String fname) { return true; };
  public static boolean Post_sanitized(Object v) { return true; };
  public static boolean Post_check(Object v) { return true; };
  public static boolean Post_check(Object v, String opr, Object value) { return true; };
  public static boolean Post_check(Object v, Object rsc, int kind, int status) { return true; };
  public static boolean Post_check_value(Object v, String opr, Object value,
                                         Object rsc, int kind, int status) { return true; };
  public static boolean Retv_is_def_from_super() { return true; };
  public static boolean Func_may_enter_recursion(Object func) { return true; };
  public static boolean Func_may_not_return(Object func) { return true; };
  public static boolean Func_is_asynchronous_safe(Object func) { return true; };
  public static boolean Func_performs_sanitize() { return true; };
  public static boolean Rsc_is_set_status(Object rsc, int kind, int status) { return true; };
  public static boolean Rsc_is_replacable(Object rsc) { return true; };
  public static boolean Rsc_is_modifiable(Object rsc) { return true; };
  public static boolean Is_automatic_variable(Object v) { return true; };
  public static boolean Is_dynamically_allocated_if_copied(Object v) { return true; };
  public static boolean Is_compatible_parm_type(int i) { return true; };
  public static boolean Do_not_get_called() { return true; };
  public static void Model_decl(boolean ret) { return; };
  public static boolean Rsc_add(Object key, String status, int kind) { return true; };
  public static Object Rsc_get(Object key, int kind) { return null; };
  public static boolean Rsc_delete(Object rsc, int kind) { return true; };
  public static boolean Rsc_set_status(Object rsc, int kind, int status) { return true; };
  public static boolean Rsc_clear_status(Object rsc, int kind, int status) { return true; };
  public static Object Get_arg(int i) { return null; };
  public static Object Get_ret() { return null; };
  public static int Get_argcnt(Object func) { return 0; };
  public static int Get_mem_size(Object expr) { return 0; };
  public static int Get_value(Object expr) { return 0; };
  public static int Get_elem_count(Object v) { return 0; };
};
