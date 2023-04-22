package edu.hit.travel.web.servlet;

import edu.hit.travel.domain.Category;
import edu.hit.travel.service.CategoryService;
import edu.hit.travel.service.impl.CategoryServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/category/*")
public class CategoryServlet extends BaseServlet {

    private CategoryService categoryService = new CategoryServiceImpl();

    /**
     * 查询所有类型
     *
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void findAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        // 1. 调用service查询所有
        List<Category> categoryList = categoryService.findAll();
        // 2. 序列化Json返回
//        ObjectMapper mapper = new ObjectMapper();
//        response.setContentType("application/json;charset=utf-8");
//        mapper.writeValue(response.getOutputStream(), categoryList);
        writeJsonValue(response, categoryList);
    }
}