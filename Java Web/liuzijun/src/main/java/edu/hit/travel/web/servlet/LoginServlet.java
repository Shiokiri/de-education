package edu.hit.travel.web.servlet;

import edu.hit.travel.domain.ResultInfo;
import edu.hit.travel.domain.User;
import edu.hit.travel.service.UserService;
import edu.hit.travel.service.impl.UserServiceImpl;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //1. 获取用户名和密码数据
        Map<String, String[]> map = request.getParameterMap();
        //2. 封装User对象
        User user = new User();
        try {
            BeanUtils.populate(user, map);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        //3. 调用service查询
        UserService service = new UserServiceImpl();
        User u = service.login(user);

        ResultInfo result = new ResultInfo();

        //4. 判断用户对象是否为null
        if (u == null) {
            //用户名密码错误
            result.setFlag(false);
            result.setErrorMsg("用户名或密码错误");
        }
        //5. 判断登录成功
        if (u != null) {
            //登录成功
            result.setFlag(true);
            request.getSession().setAttribute("user",u);
        }

        //响应数据
        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(), result);
    }
}
