package edu.hit.travel.web.servlet;

import edu.hit.travel.domain.ResultInfo;
import edu.hit.travel.domain.User;
import edu.hit.travel.service.UserService;
import edu.hit.travel.service.impl.UserServiceImpl;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

@WebServlet("/user/*")
public class UserServlet extends BaseServlet {

    private UserService service = new UserServiceImpl();

    public void regist(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Map<String, String[]> map = request.getParameterMap();
        User user = new User();
        try {
            BeanUtils.populate(user, map);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        Boolean flag = service.regist(user);

        ResultInfo result = new ResultInfo();
        if (flag) {
            result.setFlag(true);
        } else {
            result.setFlag(false);
            result.setErrorMsg("注册失败！");
        }
        ObjectMapper mapper = new ObjectMapper();
        String json = mapper.writeValueAsString(result);
        response.setContentType("application/json;charset=utf-8");
        response.getWriter().write(json);
    }

    public void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Map<String, String[]> map = request.getParameterMap();
        User user = new User();
        try {
            BeanUtils.populate(user, map);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        User u = service.login(user);
        ResultInfo result = new ResultInfo();
        if (u == null) {
            result.setFlag(false);
            result.setErrorMsg("用户名或密码错误");
        }
        else {
            result.setFlag(true);
            request.getSession().setAttribute("user", u);
        }
        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(), result);
    }

    public void findOne(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Object user = request.getSession().getAttribute("user");

        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(), user);
        //writeJsonValue(response, user);
    }

    public void exit(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.getSession().invalidate();
        response.sendRedirect(request.getContextPath() + "/login.html");
    }
}
