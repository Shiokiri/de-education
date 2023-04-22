package edu.hit.travel.service.impl;

import edu.hit.travel.dao.CategoryDao;
import edu.hit.travel.dao.impl.CategoryDaoImpl;
import edu.hit.travel.domain.Category;
import edu.hit.travel.service.CategoryService;

import java.util.ArrayList;
import java.util.List;

public class CategoryServiceImpl implements CategoryService {

    private CategoryDao categoryDao = new CategoryDaoImpl();

    @Override
    public List<Category> findAll() {
        List<Category> categoryList = new ArrayList<>();
        categoryList = categoryDao.findAll();
        return categoryList;
    }
}