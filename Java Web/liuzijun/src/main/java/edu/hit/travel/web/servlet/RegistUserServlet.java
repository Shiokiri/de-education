package edu.hit.travel.web.servlet;

import com.fasterxml.jackson.databind.ObjectMapper;
import edu.hit.travel.domain.ResultInfo;
import edu.hit.travel.domain.User;
import org.apache.commons.beanutils.BeanUtils;
import edu.hit.travel.service.UserService;
import edu.hit.travel.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

@WebServlet("/registUserServlet")
public class RegistUserServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 0. 处理编码
        // 1. 处理数据
        Map<String, String[]> parameterMap = request.getParameterMap();
        // 2. 封装对象
        User user = new User();
        try {
            BeanUtils.populate(user, parameterMap);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        // 3. 调用service完成注册
        UserService userService = new UserServiceImpl();
        boolean flag = userService.regist(user);
        ResultInfo info = new ResultInfo();
        // 4. 响应结果
        if (flag) {
            // 注册成功
            info.setFlag(true);
        } else {
            // 注册失败
            info.setFlag(false);
            info.setErrorMsg("注册失败！");
        }
        // 将info序列化为json，并写回到客户端
        ObjectMapper mapper = new ObjectMapper();
        String json = mapper.writeValueAsString(info);
        // 将json写回客户端
        response.setContentType("application/json;charset=utf-8");
        response.getWriter().write(json);
        // 也可以采用字节流的方式，但字节流的write()需要传的是byte[]，因此，需要转byte：
        // response.getOutputStream().write(json.getBytes());
        // 也可以用mapper的writeValue方法，直接将对象转出字符输出流：这样前面的json转换可以省掉
        // mapper.writeValue(response.getWriter(),info);
    }
}
