package edu.hit.travel.dao.impl;

import edu.hit.travel.dao.UserDao;
import edu.hit.travel.domain.User;
import edu.hit.travel.util.JDBCUtils;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class UserDaoImpl implements UserDao {
    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    @Override
    public User findByUsername(String username) {
        User user = null;
        try {
            String sql = "SELECT * FROM tab_user WHERE username = ?";
            user = template.queryForObject(sql, new BeanPropertyRowMapper<User>(User.class), username);
        } catch (Exception e) {
        }

        return user;
    }

    @Override
    public void saveUser(User user) {
        String sql = "INSERT INTO tab_user(username, password, name, birthday, sex, telephone, email) " +
                " VALUES (?,?,?,?,?,?,?) ";
        template.update(sql,
                user.getUsername(),
                user.getPassword(),
                user.getName(),
                user.getBirthday(),
                user.getSex(),
                user.getTelephone(),
                user.getEmail());
    }

    @Override
    public User findByUsernameAndPassword(String username, String password) {
        User user = null;
        try {
            String sql = "SELECT * FROM tab_user WHERE username = ? AND password = ?";
            user = template.queryForObject(sql, new BeanPropertyRowMapper<User>(User.class), username, password);
        } catch (Exception e) {
        }
        return user;
    }
}
