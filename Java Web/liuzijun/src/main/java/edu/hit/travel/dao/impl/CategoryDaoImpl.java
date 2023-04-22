package edu.hit.travel.dao.impl;

import edu.hit.travel.dao.CategoryDao;
import edu.hit.travel.domain.Category;
import edu.hit.travel.util.JDBCUtils;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.util.List;

public class CategoryDaoImpl implements CategoryDao {

    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    @Override
    public List<Category> findAll() {
        String sql = "SELECT * FROM tab_category ORDER BY cid";
        return template.query(sql, new BeanPropertyRowMapper<Category>(Category.class));
    }
}