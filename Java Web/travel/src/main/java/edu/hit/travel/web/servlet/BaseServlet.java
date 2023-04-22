package edu.hit.travel.web.servlet;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;


public class BaseServlet extends HttpServlet {

    /**
     * 方法分发
     *
     * @param req  请求
     * @param resp 响应
     * @throws ServletException
     * @throws IOException
     */
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // System.out.println("baseservlet的Service方法...............");
        // 根据请求的路径，获取方法名称，在通过反射方式执行方法，即可完成方法的分发工作
        // 1. 获取请求路径
        String requestURI = req.getRequestURI(); // 格式：travel/user/add
        // System.out.println(requestURI);
        // 2. 获取方法的名称
        String methodName = requestURI.substring(requestURI.lastIndexOf("/") + 1);
        // System.out.println(methodName);
        // 3. 获取方法对象Method 。 this对象谁调用我，我就代表谁
        // System.out.println(this);
        try {
            // 忽略访问权限修饰符，获取private，protected等所有方法
            // Method method = this.getClass().getDeclaredMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
            // method.setAccessible(true); //上一句将getMethod改成getDeclaredMethod后，在加上暴力反射，搞定
            Method method = this.getClass().getMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);
            // 4. 执行获取的方法
            method.invoke(this, req, resp);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

    }

    /**
     * 将传入的对象序列化为json，并且写回客户端
     *
     * @param obj  传入对象
     * @param resp 响应
     * @throws IOException io异常
     */
    public void writeJsonValue(HttpServletResponse resp, Object obj) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        resp.setContentType("application/json;charset=utf-8");
        mapper.writeValue(resp.getOutputStream(), obj);
    }

    /**
     * 将传入的对象序列化为json，返回给调用者
     *
     * @param obj 待序列化的对象
     * @return json
     */
    public String writeJsonValueAsString(Object obj) throws JsonProcessingException {
        ObjectMapper mapper = new ObjectMapper();
        return mapper.writeValueAsString(obj);
    }
}
