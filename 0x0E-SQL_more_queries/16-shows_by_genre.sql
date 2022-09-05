-- shows by genre
SELECT s.title, g.name
FROM tv_shows AS s
LEFT JOIN tv_show_genres AS tg
ON s.id = tg.show_id
LEFT JOIN tv_genres AS g
ON g.id = tg.genre_id
ORDER BY s.title, g.name;
