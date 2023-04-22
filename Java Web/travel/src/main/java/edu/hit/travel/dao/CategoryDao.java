package edu.hit.travel.dao;

import edu.hit.travel.domain.Category;

import java.util.List;

public interface CategoryDao {

    List<Category> findAll();
}