package edu.hit.travel.service;

import edu.hit.travel.domain.User;

public interface UserService {

    Boolean regist(User user);

    User login(User user);
}
