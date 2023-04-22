package edu.hit.travel.dao;

import edu.hit.travel.domain.User;

public interface UserDao {

    /**
     * 根据用户名查找用户
     *
     * @param username
     * @return
     */
    User findByUsername(String username);
    /**
     * 保存用户
     *
     * @param user
     */
    void saveUser(User user);
    /**
     * 根据账号密码查找用户
     * @param username
     * @param password
     * @return
     */
    User findByUsernameAndPassword(String username, String password);
}