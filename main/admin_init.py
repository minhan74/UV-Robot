from app.models import User
from app import db
u = User(username='admin')
u.set_password('MIS@2020')
db.session.add(u)
db.session.commit()
