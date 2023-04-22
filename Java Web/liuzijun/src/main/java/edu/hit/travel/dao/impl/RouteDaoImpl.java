package edu.hit.travel.dao.impl;

import edu.hit.travel.dao.RouteDao;
import edu.hit.travel.domain.Route;
import edu.hit.travel.util.JDBCUtils;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.util.ArrayList;
import java.util.List;

public class RouteDaoImpl implements RouteDao {

    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    @Override
    public int findTotalCount(int cid) {
        String sql = "SELECT count(*) FROM tab_route WHERE 1=1 ";
        StringBuilder sb = new StringBuilder(sql);

        List params = new ArrayList();
        if (cid != 0) {
            sb.append(" AND cid = ? ");
            params.add(cid);
        }

        sql = sb.toString();
        return template.queryForObject(sql, Integer.class, params.toArray());
    }

    @Override
    public List<Route> findByPage(int cid, int start, int pageSize) {
        String sql = "SELECT * FROM tab_route WHERE 1=1 ";
        StringBuilder sb = new StringBuilder(sql);

        List params = new ArrayList();
        if (cid != 0) {
            sb.append(" AND cid = ? ");
            params.add(cid);
        }

        sb.append(" LIMIT ?,? ");
        params.add(start);
        params.add(pageSize);

        sql = sb.toString();
        return template.query(sql, new BeanPropertyRowMapper<Route>(Route.class), params.toArray());
    }
}