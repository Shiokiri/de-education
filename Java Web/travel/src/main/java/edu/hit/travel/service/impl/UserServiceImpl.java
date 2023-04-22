package edu.hit.travel.service.impl;

import edu.hit.travel.dao.UserDao;
import edu.hit.travel.dao.impl.UserDaoImpl;
import edu.hit.travel.domain.User;
import edu.hit.travel.service.UserService;

public class UserServiceImpl implements UserService {
    private UserDao userDAO = new UserDaoImpl();

    @Override
    public Boolean regist(User user) {
        User u = userDAO.findByUsername(user.getUsername());

        if (u != null) {
            return false;
        }
        userDAO.saveUser(user);
        return true;
    }

    @Override
    public User login(User user) {
        User u = userDAO.findByUsernameAndPassword(user.getUsername(), user.getPassword());
        return u;
    }
}
